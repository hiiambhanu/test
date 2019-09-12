// Java code to perform add, 
// multiply and transpose on sparse matrices 

public class sparse_matrix { 

	// Maximum number of elements in matrix 
	int MAX = 100; 

	// Array representation 
	// of sparse matrix 
	//[][0] represents row 
	//[][1] represents col 
	//[][2] represents value 
	int data[][] = new int[MAX][3]; 

	// dimensions of matrix 
	int row, col; 

	// total number of elements in matrix 
	int len; 

	public sparse_matrix(int r, int c) 
	{ 

		// initialize row 
		row = r; 

		// initialize col 
		col = c; 

		// intialize length to 0 
		len = 0; 
	} 

	// insert elements into sparse matrix 
	public void insert(int r, int c, int val) 
	{ 

		// invalid entry 
		if (r > row || c > col) { 
			System.out.println("Wrong entry"); 
		} 

		else { 

			// insert row value 
			data[len][0] = r; 

			// insert col value 
			data[len][1] = c; 

			// insert element's value 
			data[len][2] = val; 

			// increment number of data in matrix 
			len++; 
		} 
	} 

	public void add(sparse_matrix b) 
	{ 

		// if matrices don't have same dimensions 
		if (row != b.row || col != b.col) { 
			System.out.println("Matrices can't be added"); 
		} 

		else { 

			int apos = 0, bpos = 0; 
			sparse_matrix result = new sparse_matrix(row, col); 

			while (apos < len && bpos < b.len) { 

				// if b's row and col is smaller 
				if (data[apos][0] > b.data[bpos][0] || 
				(data[apos][0] == b.data[bpos][0] && 
				data[apos][1] > b.data[bpos][1])) 

				{ 

					// insert smaller value into result 
					result.insert(b.data[bpos][0], 
								b.data[bpos][1], 
								b.data[bpos][2]); 

					bpos++; 
				} 

				// if a's row and col is smaller 
				else if (data[apos][0] < b.data[bpos][0] || 
				(data[apos][0] == b.data[bpos][0] && 
				data[apos][1] < b.data[bpos][1])) 

				{ 

					// insert smaller value into result 
					result.insert(data[apos][0], 
								data[apos][1], 
								data[apos][2]); 

					apos++; 
				} 

				else { 

					// add the values as row and col is same 
					int addedval = data[apos][2] + b.data[bpos][2]; 

					if (addedval != 0) 
						result.insert(data[apos][0], 
									data[apos][1], 
									addedval); 
					// then insert 
					apos++; 
					bpos++; 
				} 
			} 

			// insert remaining elements 
			while (apos < len) 
				result.insert(data[apos][0], 
							data[apos][1], 
							data[apos++][2]); 

			while (bpos < b.len) 
				result.insert(b.data[bpos][0], 
							b.data[bpos][1], 
							b.data[bpos++][2]); 

			// print result 
			result.print(); 
		} 
	} 

	public sparse_matrix transpose() 
	{ 

		// new matrix with inversed row X col 
		sparse_matrix result = new sparse_matrix(col, row); 

		// same number of elements 
		result.len = len; 

		// to count number of elements in each column 
		int count[] = new int[col + 1]; 

		// initialize all to 0 
		for (int i = 1; i <= col; i++) 
			count[i] = 0; 

		for (int i = 0; i < len; i++) 
			count[data[i][1]]++; 

		int[] index = new int[col + 1]; 

		// to count number of elements having col smaller 
		// than particular i 

		// as there is no col with value < 1 
		index[1] = 0; 

		// initialize rest of the indices 
		for (int i = 2; i <= col; i++) 

			index[i] = index[i - 1] + count[i - 1]; 

		for (int i = 0; i < len; i++) { 

			// insert a data at rpos and increment its value 
			int rpos = index[data[i][1]]++; 

			// transpose row=col 
			result.data[rpos][0] = data[i][1]; 

			// transpose col=row 
			result.data[rpos][1] = data[i][0]; 

			// same value 
			result.data[rpos][2] = data[i][2]; 
		} 

		// the above method ensures 
		// sorting of transpose matrix 
		// according to row-col value 
		return result; 
	} 

	public void multiply(sparse_matrix b) 
	{ 

		if (col != b.row) { 

			// Invalid multiplication 
			System.out.println("Can't multiply, "
							+ "Invalid dimensions"); 

			return; 
		} 

		// transpose b to compare row 
		// and col values and to add them at the end 
		b = b.transpose(); 
		int apos, bpos; 

		// result matrix of dimension row X b.col 
		// however b has been transposed, hence row X b.row 
		sparse_matrix result = new sparse_matrix(row, b.row); 

		// iterate over all elements of A 
		for (apos = 0; apos < len;) { 

			// current row of result matrix 
			int r = data[apos][0]; 

			// iterate over all elements of B 
			for (bpos = 0; bpos < b.len;) { 

				// current column of result matrix 
				// data[][0] used as b is transposed 
				int c = b.data[bpos][0]; 

				// temporary pointers created to add all 
				// multiplied values to obtain current 
				// element of result matrix 
				int tempa = apos; 
				int tempb = bpos; 

				int sum = 0; 

				// iterate over all elements with 
				// same row and col value 
				// to calculate result[r] 
				while (tempa < len && data[tempa][0] == r 
					&& tempb < b.len && b.data[tempb][0] == c) { 

					if (data[tempa][1] < b.data[tempb][1]) 

						// skip a 
						tempa++; 

					else if (data[tempa][1] > b.data[tempb][1]) 

						// skip b 
						tempb++; 
					else

						// same col, so multiply and increment 
						sum += data[tempa++][2] * b.data[tempb++][2]; 
				} 

				// insert sum obtained in result[r] 
				// if its not equal to 0 
				if (sum != 0) 
					result.insert(r, c, sum); 

				while (bpos < b.len && b.data[bpos][0] == c) 

					// jump to next column 
					bpos++; 
			} 

			while (apos < len && data[apos][0] == r) 

				// jump to next row 
				apos++; 
		} 

		result.print(); 
	} 

	// printing matrix 
	public void print() 
	{ 
		System.out.println("Dimension: " + row + "x" + col); 
		System.out.println("Sparse Matrix: \nRow Column Value"); 

		for (int i = 0; i < len; i++) { 

			System.out.println(data[i][0] + " "
							+ data[i][1] + " " + data[i][2]); 
		} 
	} 

	public static void main(String args[]) 
	{ 

		// create two sparse matrices and insert values 
		sparse_matrix a = new sparse_matrix(4, 4); 
		sparse_matrix b = new sparse_matrix(4, 4); 

		a.insert(1, 2, 10); 
		a.insert(1, 4, 12); 
		a.insert(3, 3, 5); 
		a.insert(4, 1, 15); 
		a.insert(4, 2, 12); 
		b.insert(1, 3, 8); 
		b.insert(2, 4, 23); 
		b.insert(3, 3, 9); 
		b.insert(4, 1, 20); 
		b.insert(4, 2, 25); 

		// Output result 
		System.out.println("Addition: "); 
		a.add(b); 
		System.out.println("\nMultiplication: "); 
		a.multiply(b); 
		System.out.println("\nTranspose: "); 
		sparse_matrix atranspose = a.transpose(); 
		atranspose.print(); 
	} 
} 

// This code is contributed by Sudarshan Khasnis 
