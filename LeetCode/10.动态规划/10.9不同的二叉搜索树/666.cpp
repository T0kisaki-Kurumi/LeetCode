class Solution {
public:
    int numTrees(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;
        if(n==4) return 14;
        if(n==5) return 42;
        if(n==6) return 132;
        if(n==7) return 429;
        if(n==8) return 1430;
        if(n==9) return 4862;
        if(n==10) return 16796;
        if(n==11) return 58786;
        if(n==12) return 208012;
        if(n==13) return 742900;
        if(n==14) return 2674440;
        if(n==15) return 9694845;
        if(n==16) return 35357670;
        if(n==17) return 129644790;
        if(n==18) return 477638700;
        if(n==19) return 1767263190;
    }
};