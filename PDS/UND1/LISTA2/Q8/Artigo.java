
import java.time.LocalDate;

public class Artigo {
    private String titulo;
    private String conteudo;
    private Autor autor; // Relacionamento: um Artigo tem um Autor
    private LocalDate dataPublicacao;
    private String status; // Ex: "Rascunho", "Em Revisão", "Revisado", "Publicado"

    public Artigo(String titulo, String conteudo, Autor autor) {
        this.titulo = titulo;
        this.conteudo = conteudo;
        this.autor = autor;
        this.dataPublicacao = null; // Inicialmente não publicado
        this.status = "Rascunho";
        autor.adicionarArtigoPublicado(this); // Adiciona o artigo à lista do autor
    }

    // Métodos Getters (Encapsulamento)
    public String getTitulo() {
        return titulo;
    }

    public String getConteudo() {
        return conteudo;
    }

    public Autor getAutor() {
        return autor;
    }

    public LocalDate getDataPublicacao() {
        return dataPublicacao;
    }

    public String getStatus() {
        return status;
    }

    // Métodos Setters (Encapsulamento)
    public void setConteudo(String conteudo) {
        this.conteudo = conteudo;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    // Método para publicar o artigo
    public void publicar() {
        if (this.status.equals("Revisado")) {
            this.dataPublicacao = LocalDate.now();
            this.status = "Publicado";
            System.out.println("Artigo '" + this.titulo + "' publicado em " + this.dataPublicacao + ".");
        } else {
            System.out.println("Artigo '" + this.titulo + "' não pode ser publicado. Status atual: " + this.status);
        }
    }

    public void enviarParaRevisao() {
        if (this.status.equals("Rascunho")) {
            this.status = "Em Revisão";
            System.out.println("Artigo '" + this.titulo + "' enviado para revisão.");
        } else {
            System.out.println("Artigo '" + this.titulo + "' já está em processo de revisão ou publicado.");
        }
    }

    public void exibirDetalhes() {
        System.out.println("--- Artigo: " + this.titulo + " ---");
        System.out.println("Autor: " + this.autor.getNome());
        System.out.println("Status: " + this.status);
        if (this.dataPublicacao != null) {
            System.out.println("Data de Publicação: " + this.dataPublicacao);
        }
        System.out.println("Conteúdo (resumo): " + this.conteudo.substring(0, Math.min(this.conteudo.length(), 100)) + "...");
    }
}