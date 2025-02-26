
import java.text.DecimalFormat;

public class Aluno {

	// Para formatar as casas decimais de uma saída double.
	private DecimalFormat df = new DecimalFormat("0.00");

	// Dados do aluno
	Integer matricula;
	String nome;
	Double P1;
	Double P2;
	Double T;

	// Construtor de um aluno.
	public Aluno(Integer matricula, String nome, Double P1, Double P2, Double T) {
		this.matricula = matricula;
		this.nome = nome;
		this.P1 = P1;
		this.P2 = P2;
		this.T = T;
	}

	// Retorna a média ponderada do aluno.
	Double media() {
		return (2.5D * P1 + 2.5D * P2 + 2.0D * T) / 7.0D;
	}

	/*
	 * Retorna a nota necessária na prova final para ser aprovado
	 * ou 0.0 caso o aluno já esteja aprovado ou reprovado.
	 * 
	 */

	double provaFinal() {
		Double media = this.media();
		if (media < 3 || media >= 7) {
			return 0.0;
		} else {
			return (50 - 6 * media) / 4;
		}
	}

	// Imprime a situação do aluno.
	void situacaoDoAluno() {
		if (this.media() >= 7) {
			System.out.println(nome + " está aprovado por média: " + df.format(this.media()));
		} else if (this.media() >= 3) {
			System.out.println(nome + " irá para a prova final e precisa de: " + df.format(this.provaFinal())
					+ " para ser aprovado.");
		}
	}
}
