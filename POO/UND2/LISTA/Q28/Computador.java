package POO.UND2.LISTA.Q28;

public class Computador extends Equipamento {
	private String modelo;
	private float preco;

	public Computador(String tipo, String marca, String modelo, float preco) {
		super(tipo, marca);
		this.modelo = modelo;
		this.preco = preco;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public float getPreco() {
		return preco;
	}

	public void setPreco(float preco) {
		this.preco = preco;
	}

	@Override
	public String toString() {
		// Utilizando os atributos herdados.
		return super.toString() +
				";\nModelo: " + this.getModelo() +
				"; Preco: " + this.getPreco()+"\n";
	}

}
