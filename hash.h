#ifndef hash_h
#define hash_h
//Linear Probing

#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;

class item
{
    public:
    int key;
    string value;
};

class hashtable
{
    public:
    int flag;
    item data;
};

hashtable* init();
int hashcode(int key);
int insert(item ,hashtable*);
int display(hashtable*);
string find(int key,hashtable*);

#endif
