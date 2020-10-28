#include<iostream>
using namespace std;

struct TrieNode
{
    bool isEnd;
    TrieNode* child[26]; //for 26 small alphabets only
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;++i)
            child[i]=NULL;
    }
};

void insert(TrieNode* root,string s)
{
    for(int i=0;i<s.length();++i)
    {
        int c=s[i]-'a'; //0 to 25
        if(root->child[c]==NULL) //node is not present
        {
            root->child[c]=new TrieNode();
        }
        root=root->child[c]; //moving to child node of current character
    }
    root->isEnd=true; //marking this end node as the end of a word
}

bool search(TrieNode* root,string s)
{
    for(int i=0;i<s.length();++i)
    {
        int c=s[i]-'a';
        if(root->child[c]==NULL) return false; //char is not present
        root=root->child[c];
    }
    return root->isEnd; 
}

void helperDisplay(TrieNode* root,string curr,string pre) 
{
    if(root->isEnd==true) cout<<pre+curr<<" "; //if this node is a end of a word
    for(int i=0;i<26;++i) //checking for every character child
    {
        if(root->child[i]!=NULL) 
        {
            helperDisplay(root->child[i],curr+char(97+i),pre);
        }
    }
}

void display(TrieNode* root,string pre) ////pre variable for printing prefix
{
    helperDisplay(root,"",pre);
}

void prefix(TrieNode* root,string pre)
{
    for(int i=0;i<pre.length();++i) //searching
    {
        int c=pre[i]-'a';
        if(root->child[c]==NULL) return; //pre is not present
        root=root->child[c];
    }
    display(root,pre);
}

int main() {
	TrieNode* root=new TrieNode(); //root is never NULL in Trie DS 
	insert(root,"bat");
	insert(root,"bad");
	insert(root,"ba");
	insert(root,"batsman");
	insert(root,"mat");
	insert(root,"matter");
	insert(root,"must");
	insert(root,"mud");
	
	cout<<"Printing available words in Trie:-\n";
	display(root,"");
	
	cout<<"\n";
	cout<<search(root,"bat")<<"\n";
	cout<<search(root,"bab")<<"\n";
	cout<<search(root,"batss")<<"\n";
	
	cout<<"\n\nPrefix words with ba :\n";
	prefix(root,"ba");
	
	cout<<"\n\nPrefix words with mu :\n";
	prefix(root,"mu");
	
	cout<<"\n\nPrefix words with ca :\n";
	prefix(root,"ca");
	return 0;
}
