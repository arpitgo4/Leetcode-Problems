class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        int result = 0;
        Map<Integer, List<Integer>> rowToSeatRes = new HashMap<>();
        for(int[] row : reservedSeats) {
            if(rowToSeatRes.containsKey(row[0])) {
                rowToSeatRes.get(row[0]).add(row[1]);
            } else {
                rowToSeatRes.put(row[0], new ArrayList<Integer>(Arrays.asList(row[1])));
            }
        }
        
        int removeCount = 0;
        for(Map.Entry<Integer, List<Integer>> entry: rowToSeatRes.entrySet()) {
            boolean front = false, middle = false, last = false;
            int count = 0;
            List<Integer> labelledRows = entry.getValue();
            for(Integer i: labelledRows) {
                if(i >=2 && i<=5) front = true;
                if(i >=6 && i<=9) last = true;
                if(i >=4 && i<=7) middle = true;
            }
            if(!front) count++;
            if(!last) count++;
            if(front && last && !middle) count++;
            removeCount += 2 - count;
        }
        return n * 2 - removeCount;
    }
}