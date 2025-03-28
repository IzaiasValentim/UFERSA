package POO.UND3.LISTA.Q39;

public class Funcionario {
	private String nome;
	private int idade;
	private String cpf;
	private double valorHoraTrabalhada;

	Funcionario(String nome, int idade, String cpf) {
		this.nome = nome;
		this.idade = idade;
		this.cpf = cpf;
		this.valorHoraTrabalhada = 2.0;
	}

	Funcionario(String nome, int idade, String cpf, double valorHora) {
		this.nome = nome;
		this.idade = idade;
		this.cpf = cpf;
		this.valorHoraTrabalhada = valorHora;
	}

	public void setValorHoraTrabalhada(double valorHora) {
		this.valorHoraTrabalhada = valorHora;
	}

	public double ganhoTotalMensal(double totalHoras) {
		return this.valorHoraTrabalhada * totalHoras;
	}

	@Override
	public String toString() {
		return "Funcionario [nome=" + nome + ", idade=" + idade + ", cpf=" + cpf + ", valorHoraTrabalhada="
				+ valorHoraTrabalhada + "]";
	}

}
