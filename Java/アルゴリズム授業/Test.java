/* * 「アルゴリズムとデータ構造」 * 大規模行列を扱うクラスの実現 * テストプログラム * Hirohito Shibata (hshibata@stf.teu.ac.jp) */class Test {    // 実行の種類    public static enum TestType    {	List,	// クラス SortList のテスト	Matrix,	// クラス SparseMatrix のテスト    }    // 最初に呼ばれる関数    public static void main(String[] args) {	// [parameter] 実行の種類	TestType type = TestType.Matrix;	switch (type) {	case List:	    System.out.println("クラス SortList のテスト");	    SortList list = new SortList();	    list.setValue(2, 2);	    list.setValue(4, 4);	    list.setValue(6, 6);	    list.setValue(3, 3);	    list.setValue(1, 1);	    list.setValue(4, 0);	    System.out.println(list.toString());	    break;	case Matrix:	    System.out.println("クラス SparseMatrix のテスト");	    SparseMatrix matrix = new SparseMatrix(10, 10);	    matrix.setValue(1, 1, 1);	    matrix.setValue(2, 2, 2);	    matrix.setValue(8, 8, 8);	    System.out.println(matrix.toString());	}    }}