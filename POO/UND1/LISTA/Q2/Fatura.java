public class Fatura {

	// Dados da fatura
	Integer numeroDeIdentificacao;
	String descricao;
	Integer quantidadeComprada;
	Double precoPorItem;

	public Fatura() {
	}

	public Integer getNumeroDeIdentificacao() {
		return numeroDeIdentificacao;
	}

	public void setNumeroDeIdentificacao(Integer numeroDeIdentificacao) {
		this.numeroDeIdentificacao = numeroDeIdentificacao;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public Integer getQuantidadeComprada() {
		return quantidadeComprada;
	}

	// Define a quantidade comprada de acordo com as regras informadas.
	public void setQuantidadeComprada(Integer quantidadeComprada) {
		if (quantidadeComprada < 0) {
			this.quantidadeComprada = 0;
		} else {
			this.quantidadeComprada = quantidadeComprada;
		}

	}

	public Double getPrecoPorItem() {
		return precoPorItem;
	}

	// Define o preço do item de acordo com as regras informadas.
	public void setPrecoPorItem(Double precoPorItem) {
		if (precoPorItem < 0) {
			this.precoPorItem = 0.0;
		} else {
			this.precoPorItem = precoPorItem;
		}

	}

	// Retorna o total da fatura.
	public Double calcularTotal() {
		return quantidadeComprada * precoPorItem;
	}

}
