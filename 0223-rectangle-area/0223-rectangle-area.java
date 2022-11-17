class Solution {
    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2-ax1)*(ay2-ay1);
        int area2 = (bx2-bx1)*(by2-by1);
        int cArea=0;
        
        if(Math.max(ax1,bx1)<=Math.min(ax2, bx2) && Math.max(ay1,by1)<=Math.min(ay2, by2)){
            int cx1=Math.max(ax1,bx1);
            int cy1=Math.max(ay1,by1);
            int cx2=Math.min(ax2,bx2);
            int cy2=Math.min(ay2,by2);
            cArea = (cx2-cx1)*(cy2-cy1);
        
        }
        
        return area1+area2-cArea;
    }
}