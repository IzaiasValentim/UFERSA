package POO.UND3.LISTA.Q42;

public class LivroDeBiblioteca extends Livro implements ItemDeBiblioteca {
	protected boolean disponibilidade; // true -> disponível
	protected String localizacao;

	public LivroDeBiblioteca(String t, String a, int qP, int anoE, String l) {
		super(t, a, qP, anoE);
		this.localizacao = l;
		this.disponibilidade = true;
	}

	@Override
	public boolean estaEmprestado() {
		return this.disponibilidade;
	}

	@Override
	public void empresta() {
		if (disponibilidade)
			disponibilidade = false;
	}

	@Override
	public void devolve() {
		if (!disponibilidade)
			disponibilidade = true;
	}

	@Override
	public String localizacao() {
		return this.localizacao;
	}

	@Override
	public String descricao() {
		return super.toString() + "\nEstá disponível: " + this.disponibilidade + "\nLocalização: " + this.localizacao;
	}
}
