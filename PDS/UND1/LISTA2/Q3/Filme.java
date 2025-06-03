
import java.util.Calendar;

public class Filme {
	private String titulo;
	private String genero;
	private int anoLancamento;
	private int classificacaoIndicativa;
	private int quantidadeDisponivel;

	public Filme(String titulo, String genero, int anoLancamento, int classificacaoIndicativa,
			int quantidadeDisponivel) {
		this.titulo = titulo;
		this.genero = genero;
		this.anoLancamento = anoLancamento;
		this.classificacaoIndicativa = classificacaoIndicativa;
		this.quantidadeDisponivel = quantidadeDisponivel;
	}

	public String exibirInformacoes() {
		return "Filme [titulo=" + titulo + ", genero=" + genero + ", anoLancamento=" + anoLancamento
				+ ", classificacaoIndicativa=" + classificacaoIndicativa + "]";
	}

	public String verificarDisponibilidade() {
		if (this.quantidadeDisponivel == 0)
			return String.format("O filme %s não está disponível", titulo);

		return String.format("O filme %s possui %d unidades disponíveis para locação", titulo, quantidadeDisponivel);
	}

	public int calcularTempoLancamento() {
		return Calendar.YEAR - anoLancamento;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public String getGenero() {
		return genero;
	}

	public void setGenero(String genero) {
		this.genero = genero;
	}

	public int getAnoLancamento() {
		return anoLancamento;
	}

	public void setAnoLancamento(int anoLancamento) {
		this.anoLancamento = anoLancamento;
	}

	public int getClassificacaoIndicativa() {
		return classificacaoIndicativa;
	}

	public void setClassificacaoIndicativa(int classificacaoIndicativa) {
		this.classificacaoIndicativa = classificacaoIndicativa;
	}

	public int getQuantidadeDisponivel() {
		return quantidadeDisponivel;
	}

	public void setQuantidadeDisponivel(int quantidadeDisponivel) {
		this.quantidadeDisponivel = quantidadeDisponivel;
	}
}