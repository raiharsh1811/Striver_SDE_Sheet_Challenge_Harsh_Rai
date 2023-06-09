#include <bits/stdc++.h>
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct Node{
    Node*links[26];
    bool flag=false;
    //checkif the refrence trie is present or not
    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    //create refrence trie
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
    //get next node to traverse
    Node *get(char ch){
        return links[ch-'a'];
    }
    //set flag true at end of word
    void setEnd(){
        flag=true;
    }
    //check if word completed
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node*root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
       //make dummy and point it to root;
       Node* node=root;
       for(int i=0;i<word.size();i++){
           if(!node->containKey(word[i])){
               //if word not there create a refrence trie
               node->put(word[i],new Node());
           }
           //moves to reference trie
           node=node->get(word[i]);
       }
       node->setEnd(); 
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node*node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};