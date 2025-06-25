package Q3;
// Interfaces de Produtos Abstratos
interface Botao {
    void renderizar();
}

interface CaixaDeTexto {
    void exibir();
}

interface Menu {
    void abrir();
}

// Implementa��es de Produtos Concretos para Tema Escuro
class BotaoEscuro implements Botao {
    @Override
    public void renderizar() {
        System.out.println("Renderizando bot�o escuro.");
    }
}

class CaixaDeTextoEscura implements CaixaDeTexto {
    @Override
    public void exibir() {
        System.out.println("Exibindo caixa de texto escura.");
    }
}

class MenuEscuro implements Menu {
    @Override
    public void abrir() {
        System.out.println("Abrindo menu escuro.");
    }
}

// Implementa��es de Produtos Concretos para Tema Claro
class BotaoClaro implements Botao {
    @Override
    public void renderizar() {
        System.out.println("Renderizando bot�o claro.");
    }
}

class CaixaDeTextoClara implements CaixaDeTexto {
    @Override
    public void exibir() {
        System.out.println("Exibindo caixa de texto clara.");
    }
}

class MenuClaro implements Menu {
    @Override
    public void abrir() {
        System.out.println("Abrindo menu claro.");
    }
}

// Implementa��es de Produtos Concretos para Tema Alto Contraste
class BotaoAltoContraste implements Botao {
    @Override
    public void renderizar() {
        System.out.println("Renderizando bot�o de alto contraste.");
    }
}

class CaixaDeTextoAltoContraste implements CaixaDeTexto {
    @Override
    public void exibir() {
        System.out.println("Exibindo caixa de texto de alto contraste.");
    }
}

class MenuAltoContraste implements Menu {
    @Override
    public void abrir() {
        System.out.println("Abrindo menu de alto contraste.");
    }
}

// Interface da F�brica Abstrata
interface FabricaDeComponentesUI {
    Botao criarBotao();
    CaixaDeTexto criarCaixaDeTexto();
    Menu criarMenu();
}

// F�bricas Concretas
class FabricaTemaEscuro implements FabricaDeComponentesUI {
    @Override
    public Botao criarBotao() {
        return new BotaoEscuro();
    }

    @Override
    public CaixaDeTexto criarCaixaDeTexto() {
        return new CaixaDeTextoEscura();
    }

    @Override
    public Menu criarMenu() {
        return new MenuEscuro();
    }
}

class FabricaTemaClaro implements FabricaDeComponentesUI {
    @Override
    public Botao criarBotao() {
        return new BotaoClaro();
    }

    @Override
    public CaixaDeTexto criarCaixaDeTexto() {
        return new CaixaDeTextoClara();
    }

    @Override
    public Menu criarMenu() {
        return new MenuClaro();
    }
}

class FabricaTemaAltoContraste implements FabricaDeComponentesUI {
    @Override
    public Botao criarBotao() {
        return new BotaoAltoContraste();
    }

    @Override
    public CaixaDeTexto criarCaixaDeTexto() {
        return new CaixaDeTextoAltoContraste();
    }

    @Override
    public Menu criarMenu() {
        return new MenuAltoContraste();
    }
}

public class Familia {
}
