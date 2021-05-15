inp_ = input().strip().split()
n = int(inp_[0])
q = int(inp_[1])

tree = [{()} for lp in range(50000 * 4 + 10)]
lazy = [(0) for lp in range(50000 * 4 + 10)]


def build(i, l, r):
    if l == r:
        tree[i].clear()
        tree[i].add((0, l))
        return

    m = (l + r) >> 1

    build(i << 1, l, m)
    build(i << 1 | 1, m + 1, r)

    tree[i] = tree[i << 1] | tree[i << 1 | 1]
    while len(tree[i]) > 5:
        (tree[i]).remove(min(tree[i]))


def addValue(i, val):
    tmp = {()}
    tmp.clear()
    while len(tree[i]) > 0:
        v_tmp = tree[i].pop()
        tmp.add((v_tmp[0] + val, v_tmp[1]))
    return tmp


def down(i):
    lazy[i << 1] += lazy[i]
    lazy[i << 1 | 1] += lazy[i]

    tree[i<<1] = addValue(i << 1, lazy[i])
    tree[i<<1|1] = addValue(i << 1 | 1, lazy[i])

    lazy[i] = 0


def update(i, l, r, u, v, val):
    if l > v or r < u:
        return
    if u <= l and r <= v:
        lazy[i] += val
        tree[i] = addValue(i, val)
        return

    m = (l + r) >> 1
    if lazy[i]!=0:
        down(i)
    update(i << 1, l, m, u, v, val)
    update(i << 1 | 1, m + 1, r, u, v, val)

    tree[i] = tree[i << 1] | tree[i << 1 | 1]
    while len(tree[i]) > 5:
        (tree[i]).remove(min(tree[i]))


build(1, 1, n)
for query_ in range(q):
    inp_ = input().split()
    typ = int(inp_[0])
    if typ == 1:
        lef = int(inp_[1])
        rig = int(inp_[2])
        val = int(inp_[3])
        update(1, 1, n, lef, rig, val)
    else:
        k = int(inp_[1])
        seg = sorted(tree[1], reverse=True)
        for i in range(min(k, n)):
            print(seg[i][1], end=' ')
        print()