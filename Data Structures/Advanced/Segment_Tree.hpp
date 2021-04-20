/*

   _____                       _        _____ _                            
  / ____|                     | |      / ____| |                           
 | (___  _   _ _   _  __ _ ___| |__   | |    | |__   __ ___   ____ _ _ __  
  \___ \| | | | | | |/ _` / __| '_ \  | |    | '_ \ / _` \ \ / / _` | '_ \ 
  ____) | |_| | |_| | (_| \__ \ | | | | |____| | | | (_| |\ V / (_| | | | |
 |_____/ \__,_|\__, |\__,_|___/_| |_|  \_____|_| |_|\__,_| \_/ \__,_|_| |_|
                __/ |                                                      
               |___/                                                       


*/


struct seg_node {

    // Properties of node

};

vector<seg_node> seg_tree(4 * MAXN);

seg_node create_leaf(ll in)
{
    seg_node leaf;

    // Assign Leaf properties

    return leaf;
}

void merge(ll node, ll left, ll right)
{
    // Merge the nodes

    return ;
}

void build(ll in, ll s, ll e, ll l, ll r)
{
    if (s == e)
    {
        seg_tree[in] = create_leaf(s);

        return ;
    }

    ll mid = (s + e) / 2;

    build(2 * in, s, mid, l, r);
    build(2 * in + 1, mid + 1, e, l, r);

    merge(in, 2 * in, 2 * in + 1);

    return ;
}

void query(ll in, ll s, ll e, ll l, ll r)       // Can be modified as we want
{
    if (e < l || r < s)
        return ;

    if (l <= s && e <= r)
    {

        return ;
    }

    ll mid = (s + e) / 2;

    query(2 * in, s, mid, l, r);

    query(2 * in + 1, mid + 1, e, l, r);

    return ;
}

void update(ll in, ll s, ll e, ll pos, ll val)  // Can be modified as we want
{
    if (s == e)
    {
        //Update leaf properties
        return ;
    }

    ll mid = (s + e) / 2;

    if (pos <= mid)
        update(2 * in, s, mid, pos, val);
    else
        update(2 * in + 1, mid + 1, e, pos, val);

    merge(in, 2 * in, 2 * in + 1);
}
