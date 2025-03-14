package POO.UND2.LISTA.Q28;

public class Equipamento {
	private String tipo;
	private String marca;

	public Equipamento(String tipo, String marca) {
		this.tipo = tipo;
		this.marca = marca;
	}

	public String getTipo() {
		return tipo;
	}

	public void setTipo(String tipo) {
		this.tipo = tipo;
	}

	public String getMarca() {
		return marca;
	}

	public void setMarca(String marca) {
		this.marca = marca;
	}

	@Override
	public String toString() {
		return "Equipamento do Tipo: " + this.getTipo() + "; Marca: " + this.getMarca();
	}
}
