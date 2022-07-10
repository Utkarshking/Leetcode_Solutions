class Solution {
public:
    int minPartitions(string n) {
        // bekaar question dimaag kharab kr diya bhai
        return *max_element(n.begin(),n.end())-'0';
    }
};