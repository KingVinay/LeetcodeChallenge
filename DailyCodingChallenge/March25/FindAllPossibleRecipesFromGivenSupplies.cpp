#include<bits/stdc++.h>
using namespace std;

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
  unordered_map<string,vector<string>> graph;
  unordered_map<string,int> indegree;
  for(int i = 0;i<recipes.size();i++){
      for(string str: ingredients[i]){
          graph[str].push_back(recipes[i]);
          indegree[recipes[i]]++;
      }
  }
  queue<string> q;
  for(string sup: supplies){
      q.push(sup);
  }
  vector<string> ans;
  while(!q.empty()){
      string item = q.front();
      q.pop();
      for(string nextRecipe: graph[item]){
          indegree[nextRecipe]--;
          if(indegree[nextRecipe]==0){
              ans.push_back(nextRecipe);
              q.push(nextRecipe);
          }
      }
  }
  return ans;
}

int main()
{
  vector<string> recipes = {"bread","butter","cheese","milk"};
  vector<vector<string>> ingredients = {{},{"butter","milk"},{"cheese","bread"},{"cheese","milk"}};
  vector<string> supplies = {"butter","cheese","milk"};
  vector<string> ans = findAllRecipes(recipes, ingredients, supplies);
  for(string s: ans){
      cout<<s<<endl;
  }
  return 0;
}