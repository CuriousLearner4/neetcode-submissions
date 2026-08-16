class Solution {
public:

    string encode(vector<string>& strs) {
        string metadata = "";
        string payload = "";
        for(int i = 0 ; i < strs.size();++i){
            metadata+= to_string(strs[i].size());
            metadata+= ',';
            payload +=strs[i];
        }
        string encodedData = "";
        encodedData += to_string(metadata.size());
        encodedData += ',';
        encodedData += metadata;
        encodedData += payload;

        return encodedData;
    }
    //first digit will be lenth of metadata
    //comaseparated values of lengths
    //4,5,5,helloworld
    //16
    vector<string> decode(string s) {
        string metadatalengthinfo = "";
        int i = 0;
        while(s[i]!=','){
            metadatalengthinfo+=s[i++];
        }
        int metadatastartindex = i+1;
        int l = stoi(metadatalengthinfo);
        string metadata = s.substr(metadatastartindex,l);
        string payload  = s.substr(l+metadatastartindex);
        int k = 0;
        int payload_idx = 0;
        vector<string> result;
        while(k < metadata.length()){
            string wordLengthS = "";
            while(k < metadata.length() && metadata[k] != ','){
                wordLengthS += metadata[k];
                k++;
            }
            k++;
            int wordlength = stoi(wordLengthS);
            result.push_back(payload.substr(payload_idx, wordlength));
            payload_idx += wordlength;
        }
        return result;
    }
};
