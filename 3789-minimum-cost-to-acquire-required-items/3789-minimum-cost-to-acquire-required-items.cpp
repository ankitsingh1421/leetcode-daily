class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long option1 = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        long long option2 = 1LL * max(need1 , need2) * costBoth;

        long long common =  min(need1 , need2);
        long long option3 =  1LL * common * costBoth;

        if(need1 > need2){
            option3 += 1LL * (need1 - need2) * cost1;
        }else{
            option3 += 1LL * (need2 - need1) * cost2;
        }

        return min({option1,option2,option3});

    }
};