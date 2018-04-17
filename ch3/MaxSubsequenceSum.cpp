#include <stdio.h>
#include <time.h>

int MaxSubsequenceSum1(int A[], int N) {
	int ThisSum, MaxSum = 0;
	for(int i = 0; i < N; i++) {
		for(int j = i; j < N; j++) {
			ThisSum = 0;
			for(int k = i; k <= j; k++)
				ThisSum += A[k];
			if(ThisSum > MaxSum) MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

int MaxSubsequenceSum2(int A[], int N) {
	int ThisSum, MaxSum = 0;
	for(int i = 0; i < N; i++) {
		ThisSum = 0;
		for(int j = i; j < N; j++) {
			ThisSum += A[j];
			if(ThisSum > MaxSum) MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

int MaxSubSum(int A[], int Left, int Right) {
	int Center, MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, LeftBorderSum;
	int MaxRightBorderSum, RightBorderSum;

	if(Left == Right) {
		if(A[Left] > 0)
			return A[Left];
		else
			return 0;
	}

	Center = Left + (Right - Left)/2;
	MaxLeftSum = MaxSubSum(A, Left, Center);
	MaxRightSum = MaxSubSum(A, Center+1, Right);

	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for(int i = Left; i <= Center; i++) {
		LeftBorderSum += A[i];
		if(LeftBorderSum > MaxLeftBorderSum) 
			MaxLeftBorderSum = LeftBorderSum;
	}

	MaxRightBorderSum = 0; RightBorderSum = 0;
	for(int i = Center+1; i <= Right; i++) {
		RightBorderSum += A[i];
		if(RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	int max;
	if(MaxLeftSum > MaxRightSum) 
		max = MaxLeftSum;
	else max = MaxRightSum;
	if(MaxLeftBorderSum+MaxRightBorderSum > MaxLeftSum)
		max = MaxLeftBorderSum+MaxRightBorderSum;
	return max;

}

int MaxSubsequenceSum3(int A[], int N) {
	return MaxSubSum(A, 0, N-1);
}

int MaxSubsequenceSum4(int A[], int N) {
	int ThisSum = 0, MaxSum = 0;
	for(int i = 0; i < N; i++) {
		ThisSum += A[i];
		if(ThisSum > MaxSum) MaxSum = ThisSum;
		else if(ThisSum < 0) ThisSum = 0;
	}
	return MaxSum;
}
int main() {
	int A[10] = {1,3,23,-12,34,1,2,0,-34,23};
	int N = 10;
	printf("MaxSum is %d %d %d %d.\n",MaxSubsequenceSum1(A, N), MaxSubsequenceSum2(A, N), 
		MaxSubsequenceSum3(A, N), MaxSubsequenceSum4(A, N));

	printf("%.5f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0; 
}