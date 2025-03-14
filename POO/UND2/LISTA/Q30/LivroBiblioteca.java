package POO.UND2.LISTA.Q30;

public class LivroBiblioteca extends Livro {
	private String nomeBiblioteca;
	private int unidadesDisponiveis;

	public LivroBiblioteca(String titulo, String autor, int numPaginas, String nomeBiblioteca,
			int unidadesDisponiveis) {
		super(titulo, autor, numPaginas);

		this.nomeBiblioteca = nomeBiblioteca;
		this.unidadesDisponiveis = unidadesDisponiveis;

	}

	public String getNomeBiblioteca() {
		return nomeBiblioteca;
	}

	public void setNomeBiblioteca(String nomeBiblioteca) {
		this.nomeBiblioteca = nomeBiblioteca;
	}

	public int getUnidadesDisponiveis() {
		return unidadesDisponiveis;
	}

	public void setUnidadesDisponiveis(int unidadesDisponiveis) {
		this.unidadesDisponiveis = unidadesDisponiveis;
	}

	@Override
	public String toString() {
		return String.format("%s possui %d unidades disponível na biblioteca %s.", this.getTitulo(),
				this.getUnidadesDisponiveis(), this.getNomeBiblioteca());
				
	}
}
