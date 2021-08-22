//
//  main.cpp
//  StableMatchingAlgorithm
//
//  Created by Brando Flores on 8/21/21.
//

#include <iostream>
#include <vector>
using namespace std;

void stableMatch();
void buildSampleData();
void print(vector<vector<string>> v);

/*
 Use a dating site format as and example, pairing a man and woman with each other.
 A man can propose to a woman, a woman can accept or deny.
 A person can be engaged or available.
 This is a man-optimal assignment. Each man receives the best valid partner.
 Perfect matching: everyone is matched monogamously
    Each man gets exactly one woman
    Each woman get exactly one man
 Stability: No incentive for some pair of participants to undermine assignment by join action.
    In matching M, an unmatched pair m-w is UNSTABLE if man m and woman w prefer
    each other to current partners.
    Unstable pair m-w could each improve by eloping.
 Stable matching: perfect matching with no unstable pairs
 Stable matching problem: Given the preference lists of n men and n women,
    find a stable matching if one exists.
 */

/*********** Unstable Sample Data ***********
 
 favorite (1st) -> least favorite (3rd)
 + = who user was matched to
  -----------------------
 |Mens Preference Profile|
  -----------------------
        | 1st     | 2nd    | 3rd
 Xavier | Amy     | Bertha | Clare+
 Yancey | Bertha+ | Amy    | Clare
 Zeus   | Amy+    | Bertha | Clare
 
 --------------------------
|Women's Preference Profile|
 --------------------------
       | 1st     | 2nd     | 3rd
Amy    | Yancey  | Xavier  | Zeus+
Bertha | Xavier  | Yancey+ | Zeus
Clare  | Xavier+ | Yancey  | Zeus
 
 This is unstable because Bertha and Xavier will hook up.
 Xavier prefers Bertha to Clare, and Bertha prefers Xavier to Yancey.
 They prefer each other over their current partners.
 */

/*********** Stable Sample Data ***********
 
 favorite (1st) -> least favorite (3rd)
 + = who user was matched to
  -----------------------
 |Mens Preference Profile|
  -----------------------
        | 1st     | 2nd    | 3rd
 Xavier | Amy+    | Bertha | Clare
 Yancey | Bertha+ | Amy    | Clare
 Zeus   | Amy     | Bertha | Clare+
 
 --------------------------
|Women's Preference Profile|
 --------------------------
       | 1st     | 2nd     | 3rd
Amy    | Yancey  | Xavier+ | Zeus
Bertha | Xavier  | Yancey+ | Zeus
Clare  | Xavier  | Yancey  | Zeus+
 
 This is stable because each matched pair would rather be with each other
 than someone else given that mostly everyone is matched with their first preference.
 Note that not everyone is going to be matched with their top choice.
 */

// Global sample data
vector<vector<string>> mp;  // men's preference
vector<vector<string>> wp;  // women's preference

int main(int argc, const char * argv[]) {
    buildSampleData();
    print(mp);
    print(wp);
    
    return 0;
}

/*
 Helper to build sample data
 */
void buildSampleData() {
    mp = {
        {"x", "a", "b", "c"},
        {"y", "b", "a", "c"},
        {"z", "a", "b", "c"}
    };
    wp = {
        {"a", "y", "x", "z"},
        {"b", "x", "y", "z"},
        {"c", "x", "y", "z"}
    };
}

/*
 Helper to print 2D array
 */
void print(vector<vector<string>> v) {
    if (v[0][0] == "x") {
        cout << "Men's preferences:" << endl;
    } else {
        cout << "Women's preferences:" << endl;
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

/* Pseudo-code
 Initialize each person to be free
 while (some man is free and hasn't proposed to every woman)         | O(1)
    Choose such a man m                                              | O(1)
    w = 1st woman on m's list to whom m has not yet proposed         | O(1)
    if (w is free)                                                   | O(1)
        assign m and w to be engaged                                 | O(1)
    else if (w prefers m to her fiance m')                           | O(n)
        assign m and w to be engaged, and m' to be free
    else
        w rejects m
 */
void stableMatch() {
    
}
