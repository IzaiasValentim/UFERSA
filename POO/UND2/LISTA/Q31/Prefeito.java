package POO.UND2.LISTA.Q31;

public class Prefeito extends Politico {
	private String cidade;

	public Prefeito(String nome, int idade, String partido, String cidade) {
		super(nome, idade, partido);

		this.cidade = cidade;
	}
	
	@Override
	public String toString() {
		return String.format("Função: %s\nCidade: %s", this.getClass().getSimpleName(), cidade) + super.toString();
	}

}
