
public class Time {
	String nomeDoTime;
	String nomeDoTecnico;
	String cidade;
	Integer quantidadeDeJogadores;
	String categoria;
	int vitorias;
	int derrotas;
	int empates;
	String codigoCampeonado;

	public Time() {
	}

	public Time(String nomeDoTime, String nomeDoTecnico, String cidade, Integer quantidadeDeJogadores, String categoria,
			int vitorias, int derrotas, int empates, String codigoCampeonado) {
		this.nomeDoTime = nomeDoTime;
		this.nomeDoTecnico = nomeDoTecnico;
		this.cidade = cidade;
		this.quantidadeDeJogadores = quantidadeDeJogadores;
		this.categoria = categoria;
		this.vitorias = vitorias;
		this.derrotas = derrotas;
		this.empates = empates;
		this.codigoCampeonado = codigoCampeonado;
	}

	Boolean validarCadastro() {
		return (!nomeDoTime.equals(" ") && !nomeDoTecnico.equals(" ") && cidade.equals(" ")
				&& quantidadeDeJogadores != 0 && !categoria.equals(" ") && codigoCampeonado.equals(" "));
	}

	void computarVitoria() {
		vitorias++;
	}

	void computarDerrota() {
		derrotas++;
	}

	void computarEmpate() {
		empates++;
	}

	void situacaoDoTime() {
		System.out.println("\n- Vitórias: " + vitorias + "\n- Derrotas: " + derrotas + "\n- Empates: " + empates);
	}

	void dadosDoTime() {
		System.out.println("\n- Nome do time: " + nomeDoTime + "\n- Nome do técnico: " + nomeDoTecnico + "\n- Cidade: "
				+ cidade + "\n- Quantidade de jogadores: " + quantidadeDeJogadores + "\n- Categoria: " + categoria
				+ "\n- Código do campeonato: " + codigoCampeonado);
	}
}
