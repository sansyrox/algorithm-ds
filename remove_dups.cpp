int removeDuplicates(vector<int>& v) {    
        vector<int>::iterator ip; 
  
    // Using std::unique 
    ip = std::unique(v.begin(), v.end()); 
    // * means undefined 
  
    // Resizing the vector so as to remove the undefined terms 
    v.resize(std::distance(v.begin(), ip));
        
        
    return v.size();
    }