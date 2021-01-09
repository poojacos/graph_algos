# Solving Leetcode Problem 269: Alien Dictionary
# Topological sort using queue

class TrieNode:
    def __init__(self, c):
        self.c = c
        self.children = {}

class Trie:
    def __init__(self):
        self.root = TrieNode("")
        
    def insert(self, word, adj, indegree):
        root = self.root
        for c in word:
            if c in root.children:
                if len(adj[c])!=0:
                    return adj, indegree, False
                root = root.children[c]
            else:
                newNode = TrieNode(c)
                for child in root.children:
                    if  c not in adj[child]:
                        adj[child].add(c)
                        indegree[c]+=1
                
                root.children[c] = newNode
                root = newNode
        
        if len(root.children)!=0: # there exists a longer string that came befor with same prefix
            return adj, indegree, False
        
        return adj, indegree, True
    
class Solution:
    
    def alienOrder(self, words: List[str]) -> str:
        root = Trie()
        adj = {}
        indegree = {}
        for word in words:
            for ch in word:
                adj[ch] = set()
        

        for key in adj:
            indegree[key]=0
        
        for word in words:
            adj, indegree, val = root.insert(word, adj, indegree)
            if not val:
                return ""
        
        print(adj, indegree)
        
        q = []
        for i in indegree:
            if indegree[i]==0:
                q.append(i)
        
        topSort = []
        i = len(q)
        while i>0:
            top = q[-1]
            q.pop()
            topSort.append(top)
            s = adj[top]
            for neighbour in s:
                indegree[neighbour]-=1
                if indegree[neighbour]==0:
                    q.append(neighbour)
            i = len(q)
            
        if len(topSort)!=len(adj):
            return ""
        return "".join(topSort)
                    
            
        
        
        
        