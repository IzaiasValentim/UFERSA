package POO.UND2.LISTA.Q30;

public class Main {
	public static void main(String[] args) {
		// Instânciando um livro de uma biblioteca:
		LivroBiblioteca lBiblioteca = new LivroBiblioteca("POO", "Autor", 545, "BCZM", 15);
		System.out.println(lBiblioteca);

		// Livro de uma livraria:
		LivroLivraria livroLivraria = new LivroLivraria("Banco de dados", "Autor", 325, "Livros+", 75.59);
		System.out.println(livroLivraria);

	}
}
