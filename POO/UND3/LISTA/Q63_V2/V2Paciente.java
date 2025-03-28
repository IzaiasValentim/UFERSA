package POO.UND3.LISTA.Q63_V2;

public class V2Paciente implements Comparable<V2Paciente> {

	public int rg;
	public int idade;

	public V2Paciente(int rg, int idade) {
		this.rg = rg;
		this.idade = idade;
	}

	public int getIdade() {
		return this.idade;
	}

	@Override
	public int compareTo(V2Paciente outro) {
		return Integer.compare(outro.getIdade(), this.getIdade());
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("V2Paciente{");
		sb.append("rg=").append(rg);
		sb.append(", idade=").append(idade);
		sb.append('}');
		return sb.toString();
	}

}
