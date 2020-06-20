//
// Created by shangqi on 2020/6/17.
//

#include "SSEServer.h"

SSEServer::SSEServer() {
    tags.clear();
    dict.clear();
}

void SSEServer::add_entries(const string& label, const string& tag, vector<string> ciphertext_list) {
    tags[label] = tag;
    dict[label] = move(ciphertext_list);
}

vector<int> SSEServer::search(uint8_t *token, unordered_map<long, uint8_t *> keys) {
    int counter = 0;
    vector<int> res_list;
    while (true) {
        // get label string
        uint8_t label[DIGEST_SIZE];
        hmac_digest((uint8_t*) &counter, sizeof(int),
                    token, DIGEST_SIZE,
                    label);
        string label_str((char*) label, DIGEST_SIZE);
        counter++;
        // terminate if no label
        if(tags.find(label_str) == tags.end()) break;
        // get the insert position of the tag
        vector<long> search_pos = BloomFilter<32, GGM_SIZE, HASH_SIZE>::get_index((uint8_t*) tags[label_str].c_str());
        sort(search_pos.begin(), search_pos.end());
        // derive the key from search position and decrypt the id
        vector<string> ciphertext_list = dict[label_str];
        for (int i = 0; i < min(search_pos.size(), ciphertext_list.size()); ++i) {
            uint8_t res[4];
            if(keys[search_pos[i]] == nullptr) break;
            aes_decrypt((uint8_t *) (ciphertext_list[i].c_str() + AES_BLOCK_SIZE), ciphertext_list[i].size() - AES_BLOCK_SIZE,
                        keys[search_pos[i]], (uint8_t *) ciphertext_list[i].c_str(),
                        res);
            res_list.emplace_back(*((int*) res));
            break;
        }
    }
    return res_list;
}