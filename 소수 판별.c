bool solution(int k){
	if(k%2==0 || k%3==0 && k!=1)
		return false;
	
	return true;
	
}