class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int total=0;
        int lastG=0;
        int lastP=0;
        int lastM=0;

        for(int i=0;i<garbage.size();i++){

            for(char c: garbage[i]){
                total++;

            if(c=='M'){
                lastM=i;
            }
            else if(c=='P'){
                lastP=i;
            }
            else if(c=='G'){
                lastG=i;
            }
            }
        }

            int paperTravel=0;
            for(int i=0;i<lastP;i++){
                total+=travel[i];
            }

            int glassTravel=0;
            for(int i=0;i<lastG;i++){
                total+=travel[i];
            }

            for(int i=0;i<lastM;i++){
                total+=travel[i];
            }
        return total;
    }
};