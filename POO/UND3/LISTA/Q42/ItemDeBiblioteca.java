package POO.UND3.LISTA.Q42;

public interface ItemDeBiblioteca {
	public int maximoDeDiasParaEmpresito = 14;

	public boolean estaEmprestado();

	public void empresta();

	public void devolve();

	public String localizacao();

	public String descricao();
}
