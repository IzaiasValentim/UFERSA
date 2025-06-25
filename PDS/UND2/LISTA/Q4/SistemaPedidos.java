package Q4;

// Componente (Interface)
interface Pedido {
    String getDescricao();
    double calcularCusto();
}

// Componente Concreto
class PedidoSimples implements Pedido {
    @Override
    public String getDescricao() {
        return "Pedido Simples";
    }

    @Override
    public double calcularCusto() {
        return 50.0; // Custo base do pedido
    }
}

// Decorador Abstrato
abstract class DecoradorDePedido implements Pedido {
    protected Pedido pedidoDecorado;

    public DecoradorDePedido(Pedido pedidoDecorado) {
        this.pedidoDecorado = pedidoDecorado;
    }

    @Override
    public String getDescricao() {
        return pedidoDecorado.getDescricao(); // Delega ao objeto embrulhado
    }

    @Override
    public double calcularCusto() {
        return pedidoDecorado.calcularCusto(); // Delega ao objeto embrulhado
    }
}

// Decoradores Concretos
class EmbalagemParaPresenteDecorador extends DecoradorDePedido {
    public EmbalagemParaPresenteDecorador(Pedido pedidoDecorado) {
        super(pedidoDecorado);
    }

    @Override
    public String getDescricao() {
        return super.getDescricao() + ", com Embalagem para Presente";
    }

    @Override
    public double calcularCusto() {
        return super.calcularCusto() + 10.0; // Adiciona custo da embalagem
    }
}

class FreteExpressoDecorador extends DecoradorDePedido {
    public FreteExpressoDecorador(Pedido pedidoDecorado) {
        super(pedidoDecorado);
    }

    @Override
    public String getDescricao() {
        return super.getDescricao() + ", com Frete Expresso";
    }

    @Override
    public double calcularCusto() {
        return super.calcularCusto() + 25.0; // Adiciona custo do frete
    }
}

class SeguroDecorador extends DecoradorDePedido {
    public SeguroDecorador(Pedido pedidoDecorado) {
        super(pedidoDecorado);
    }

    @Override
    public String getDescricao() {
        return super.getDescricao() + ", com Seguro";
    }

    @Override
    public double calcularCusto() {
        return super.calcularCusto() + 15.0; // Adiciona custo do seguro
    }
}

public class SistemaPedidos {
}
