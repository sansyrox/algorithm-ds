class Solution {
    public boolean validUtf8(int[] data) {
        int count = 0;
        for(int i : data){
            if((i>>3) == 0b11110){
                if(count > 0) return false;
                count = 3;
            }else if((i>>4) == 0b1110){
                if(count > 0) return false;
                count = 2;
            }else if((i>>5) == 0b110){
                if(count > 0) return false;
                count = 1;
            }else if((i>>7) == 0){
                if(count > 0) return false;
            }else if((i>>6) == 0b10){
                if(count <= 0) return false;
                count--;
            }else{
                return false;
            }
        }
        if(count == 0) return true;
        return false;
    }
}