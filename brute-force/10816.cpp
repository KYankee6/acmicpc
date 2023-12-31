int[][] arr = new int[N][2]; 
 
for(int i = 0; i < N; i++) {
	arr[i][0] = input();	// [i][0] : 몸무게
	arr[i][1] = input();	// [i][1] : 키
}
		
for(int i = 0; i < N; i++) {
	int rank = 1;	// rank 는 1 부터 시작
			
	for(int j = 0; j < N; j++) {
		if(i == j) continue;	// 같은 사람은 비교할 필요가 없음
 
		if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
			rank++;
		}
	}
 
	print(rank + " ");
 
}
 