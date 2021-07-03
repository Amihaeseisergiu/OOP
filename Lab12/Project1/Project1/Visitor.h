#pragma once

using namespace std;

class Lamaie;
class Mar;
class Grapefruit;
class Portocala;

class Visitor
{
public:
	virtual void visit(Portocala& orange) = 0;
	virtual void visit(Lamaie& lemon) = 0;
	virtual void visit(Grapefruit& grape) = 0;
	virtual void visit(Mar& apple) = 0;
};

