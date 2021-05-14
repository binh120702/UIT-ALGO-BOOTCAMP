inp_ = input().strip().split()
n = int(inp_[0])
q = int(inp_[1])

class node:
    def __init__(self):
        self.h = []
        for i in range(5):
            self.h.append([-50000000000000,0])
        self.lazy = 0 

tree = []
for i in range(n*5+10): 
    tree.append(node())

def build(i, l, r):
    idr = 0
    if l==r:
        tree[i].h[0] = [0,l]
        return 

    m = (l+r) >> 1
    il = i<<1
    ir = i<<1|1

    build(il,l,m)
    build(ir,m+1,r)

    idl = 0
    idr = 0
    for id in range(min(5,r-l+1)):
        if tree[il].h[idl]>tree[ir].h[idr]:
            tree[i].h[id][0] = tree[il].h[idl][0]
            tree[i].h[id][1] = tree[il].h[idl][1]
            idl+=1
        else:    
            tree[i].h[id][0] = tree[ir].h[idr][0]
            tree[i].h[id][1] = tree[ir].h[idr][1]
            idr+=1

def down(i, l, r):
    il = i<<1
    ir = i<<1|1
    tree[il].lazy+= tree[i].lazy
    tree[ir].lazy+= tree[i].lazy
    for j in range(min(5,r-l+1)):
        tree[i].h[j][0]+= tree[i].lazy
    tree[i].lazy = 0


def update(i, l, r, u, v, val):
    down(i,l,r)
    if l>v or r<u:
        return 
    if u<=l and r<=v:
        tree[i].lazy+= val
        down(i,l,r)
        return
    
    m = (l+r) >> 1
    il = i<<1
    ir = i<<1|1
    down(i,l,r)
    
    update(il,l,m,u,v,val)
    update(ir,m+1,r,u,v,val)

    idl = 0
    idr = 0
    for id in range(min(5,r-l+1)):
        if tree[il].h[idl]>tree[ir].h[idr]:
            tree[i].h[id][0] = tree[il].h[idl][0]
            tree[i].h[id][1] = tree[il].h[idl][1]
            idl+=1
        else:    
            tree[i].h[id][0] = tree[ir].h[idr][0]
            tree[i].h[id][1] = tree[ir].h[idr][1]
            idr+=1


build(1,1,n)
for query_ in range(q):
    inp_ = input().strip().split()
    typ = int(inp_[0])
    if typ==1:
        lef = int(inp_[1])
        rig = int(inp_[2])
        val = int(inp_[3])
        update(1,1,n,lef,rig,val)
    else:
        k = int(inp_[1])
        for j in range(min(k,n)):
            print(tree[1].h[j][1], end=' ')
        print()