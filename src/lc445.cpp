#include "header/list_utils.hpp"
#include "header/common.h"
class Solution {
    void to_stack(ListNode* l, stack<int>&s){
        while(l){
            s.push(l->val);
            l=l->next;
        }
    }
    void add(stack<int>& s1,stack<int>&s2,int& sum,int& carry){
        int val1=0;
        if(not s1.empty()){
            val1=s1.top();
            s1.pop();
        }
        int val2=0;
        if(not s2.empty()){
            val2=s2.top();
            s2.pop();
        }
        sum=(val1+val2+carry)%10;
        carry=(val1+val2+carry)/10;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        to_stack(l1,s1);
        to_stack(l2,s2);
        int sum=0;
        int carry=0;
        ListNode*head= nullptr;
        while(not(s1.empty() and s2.empty())){
            add(s1,s2,sum,carry);
            ListNode* new_head=new ListNode(sum);
            new_head->next=head;
            head=new_head;
        }
        if(carry!=0){
            ListNode* new_head=new ListNode(carry);
            new_head->next=head;
            head=new_head;
        }
        return head;
    }
};
int main(){
    ListNode* l1= build_list(vector<int>{7,2,4,3});
    ListNode* l2= build_list(vector<int>{5,6,4});
    Solution sol;
    ListNode* l3=sol.addTwoNumbers(l1,l2);
    print_list(l3);
    return 0;
}