struct SegTree{
    vector<long long> tree;
    SegTree(int n) { tree.resize(4*n);}

    long long query(int l,int r,int st,int en,int node = 1){
        if(st>r || en<l) return 0;
        if(st>=l && en<=r){
            return tree[node];
        }
        int mid = (st+en)/2;
        return query(l,r,st,mid,2*node) + query(l,r,mid+1,en,2*node+1);
    }

    void update(int pos, long long val,int st,int en,int node = 1){
        if(pos<st || pos>en){
            return;
        }
        if(st==en){
            tree[node] = val;
            return ;
        }
        int mid = (st+en)/2;
        update(pos,val,st,mid,2*node);
        update(pos,val,mid+1,en,2*node+1);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
};
bool isPeak(int i,vector<int> & nums){
    int n = nums.size();
    if(i>0 && i<n-1){
        return (nums[i]>nums[i+1] && nums[i]>nums[i-1]);
    }
    return false;
}

void erase(int idx,int n,set<int> & p,SegTree & tr1,SegTree & tr2,vector<int> & nums){
    auto it  = p.lower_bound(idx);
    if(it==p.end() || *it!=idx) return;

    tr1.update(idx,0,0,n-1);
    it++;
    int idx2 = -1;
    if(it!=p.end()){
        idx2 = *it;
        tr2.update(idx2,0,0,n-1);
    }

    it--;
    tr2.update(idx,0,0,n-1);

    if(it!=p.begin() && idx2!=-1){
        it--;
        int idx1 = *it;
        tr2.update(idx2,1ll*idx2*idx1,0,n-1);

    }
    p.erase(idx);

}

void add(int idx,int n,set<int> & p,SegTree & tr1,SegTree & tr2,vector<int> & nums){
    if(!isPeak(idx,nums)) return;
    p.insert(idx);
    auto it = p.upper_bound(idx);
    int idx2 = -1;
    if(it!=p.end()){
        idx2 = *it;

    }
    it--;
    int idx1 = -1;
    if(it!=p.begin()){
        it--;
        idx1 = *it;
    }
    tr1.update(idx,1ll*idx*idx,0,n-1);
    if(idx2!=-1) tr2.update(idx2,1ll*idx2*idx,0,n-1);
    if(idx1!=-1) tr2.update(idx,1ll*idx1*idx,0,n-1);
}
class Solution {
public:
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n  = nums.size();
        set<int> p;
        for(int i = 1;i<n-1;i++){
            if(isPeak(i,nums)){
                p.insert(i);
            }
        }

        SegTree tr1(n),tr2(n);
        for(int i = 1;i<n-1;i++){
            auto it = p.lower_bound(i);
            if(it!=p.end() && *it==i){
                tr1.update(i,1ll*i*i,0,n-1);

                if(it!=p.begin()){
                    it--;
                    tr2.update(i,1ll*i*(*it),0,n-1);
                }
            }
        }
        vector<long long> ans;
        for(auto q:queries){
            int t = q[0];
            if(t==1){
                int l = q[1],r = q[2];
                if(r-l+1<3) {
                    ans.push_back(0);
                    continue;
                }
                auto it = p.lower_bound(r);
                if(it==p.begin() || *(--it)<=l){
                    ans.push_back(0);
                    continue;
                }

                long long curr = 1ll*r*(*it)-1ll*r*l-tr1.query(l+1,r-1,0,n-1)+tr2.query(l+1,r-1,0,n-1);

                it = p.lower_bound(l+1);
                int idx1 = *it;
                curr+=1ll*idx1*l;
                if(it!=p.begin()){
                    it--;
                    curr-=1ll*idx1*(*it);
                }
                ans.push_back(curr);
            }else{
                int idx = q[1],val = q[2];
                for(int j = idx-1;j<=idx+1;j++){
                    erase(j,n,p,tr1,tr2,nums);
                }
                nums[idx] = val;
                for(int j = idx-1;j<=idx+1;j++){
                    add(j,n,p,tr1,tr2,nums);
                }
            }
        }
        return ans;


    }
};