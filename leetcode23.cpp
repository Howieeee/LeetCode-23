/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    #define pii pair<int,int>
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue< pii ,vector<pii>  ,greater<pii> > pq;
        unordered_map<int,int> count;
        for(int i=0;i<lists.size();i++){
            auto it = lists[i];
            while(it){
                count[it->val]++;
                it = it->next;
            }
        }
        
        //cout << count.size() << endl;
        if(count.size()==0){
            return NULL;
        }
            
        
        for(auto n:count){
           // cout << count[i] << " " << count[i] << endl;
            pq.push({n.first,n.second});
        }
        ListNode* ans = new ListNode();
        auto it = ans;
        bool first = true;
        while(!pq.empty()){
            
            auto node = pq.top();
            
            if(it==ans && first){
                cout << node.first ;
                it->val = node.first;
                node.second--;
                first = false;
                //it = it->next;
            }
            int times = node.second;//次數
            while(times--){
                ListNode* t = new ListNode(node.first);
                it->next =t;
                it = it->next;
            }
            pq.pop();
        }
        //cout << c;
        
        return ans;
    }
};
