package POO.UND2.LISTA.Q31;

public class Governador extends Politico {
	private String estado;

	public Governador(String nome, int idade, String partido, String estado) {
		super(nome, idade, partido);

		this.estado = estado;
	}

	@Override
	public String toString() {
		return String.format("Função: %s\nEstado: %s", this.getClass().getSimpleName(), estado) + super.toString();
	}
}
