package POO.UND2.LISTA.Q30;

public class LivroLivraria extends Livro {
	private String nomeLivraria;
	private double preco;

	public LivroLivraria(String titulo, String autor, int numPaginas, String nomeLivraria, double preco) {
		super(titulo, autor, numPaginas);

		this.nomeLivraria = nomeLivraria;
		this.preco = preco;
	}

	public String getNomeLivraria() {
		return nomeLivraria;
	}

	public void setNomeLivraria(String nomeLivraria) {
		this.nomeLivraria = nomeLivraria;
	}

	public double getPreco() {
		return preco;
	}

	public void setPreco(double preco) {
		this.preco = preco;
	}

	@Override
	public String toString() {
		return String.format("%s disponível na livrária %s por %.2f", this.getTitulo(), this.getNomeLivraria(),
				this.getPreco());
	}
}
