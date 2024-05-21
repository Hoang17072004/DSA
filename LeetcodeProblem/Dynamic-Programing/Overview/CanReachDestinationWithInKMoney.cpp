Gán mọi (i,j) là chưa thăm
Gan Min[i][j] bằng dương vô cùng với mọi (i,j)
Min[0][M]=0;
While(TRUE) 
	Trong số những trạng thái chưa thăm (i,j) tìm cái có Min[i][j]
	nhỏ nhất. Giả sử nó là (k,l).
	
	Nếu không tìm được (k,l) nào mà Min[k][l] nhỏ hơn dương vô cùng - thoát vòng lặp.
	
	Đánh dấu (k,l) đã thăm
	
	For All Neighbors p of Vertex k
		If(l-S[p]>=0 AND
		 	Min[p][l-S[p]]>Min[k][l]+Dist[k][p]) 
		 		Then Min[p][l-S[p]]=Min[k][l]+Dist[k][p]
		i.e.
	Nếu tại (i,j) có đủ tiền để đi qua p (l-S[p] là số tiền còn lại sau khi đi qua p), và đường đi ngắn nhất của (p,l-S[p]) lớn hơn [đường đi ngắn nhất tới (k,l)]+[Khoảng cách từ k tới p]),
	thì gán (i,j) bằng tổng này
	End For
End While
Tìm số nhỏ nhất trong các Min[N-1][j](for all j,0<=j<=M);
Nếu có nhiều hơn một trạng thái, lấy trạng thái nào có j lớn nhất. Nếu không có (N-1,j) nào nhỏ hơn dương vô cùng -không tồn tại đường đi 