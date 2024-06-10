using System;
using System.Collections.Generic;

public class Interpreter
{
    private Parser _parser;
    private Dictionary<string, double> _globalScope;

    public Interpreter(Parser parser)
    {
        _parser = parser;
        _globalScope = new Dictionary<string, double>();
    }

    private double Visit(AST node)
    {
        if (node is BinOp binOp)
        {
            return VisitBinOp(binOp);
        }
        if (node is Num num)
        {
            return VisitNum(num);
        }
        if (node is Var varNode)
        {
            return VisitVar(varNode);
        }
        if (node is Assign assign)
        {
            return VisitAssign(assign);
        }

        throw new Exception("Invalid AST node");
    }

    private double VisitBinOp(BinOp node)
    {
        if (node.Op.Type == TokenType.Plus)
        {
            return Visit(node.Left) + Visit(node.Right);
        }
        if (node.Op.Type == TokenType.Minus)
        {
            return Visit(node.Left) - Visit(node.Right);
        }
        if (node.Op.Type == TokenType.Multiply)
        {
            return Visit(node.Left) * Visit(node.Right);
        }
        if (node.Op.Type == TokenType.Divide)
        {
            return Visit(node.Left) / Visit(node.Right);
        }

        throw new Exception("Invalid binary operator");
    }

    private double VisitNum(Num node)
    {
        return double.Parse(node.Value);
    }

    private double VisitVar(Var node)
    {
        var varName = node.Value;
    }
}