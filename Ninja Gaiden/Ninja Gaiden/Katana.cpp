#include "Katana.h"
#include "Textures.h"
Katana* Katana::m_instance = NULL;
Katana* Katana::GetInstance()
{
	if (m_instance == NULL)
		m_instance = new Katana();
	return m_instance;
}
Katana::Katana()
{

}
Katana::~Katana()
{

}
void Katana::LoadResource()
{
}


void Katana::Render()
{
	/*RenderBoundingBox();*/
}

void Katana::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	//Katana cho Ryu nen Object la Ryu
	float Ol, Ot, Or, Ob;
	int direction;
	Obj->GetBoundingBox(Ol, Ot, Or, Ob);
	direction = Obj->GetDirection();
	if (direction > 0)
	{
		l = Or;
		t = Ot;
		r = l + KATANA_W + 1;
		b = t + KATANA_H + 1;
	}
	else
	{
		r = Ol;
		t = Ot;
		b = t + KATANA_H - 1;
		l = Ol - KATANA_W;;


	}

}
bool Katana::IsCollision(LPGAMEOBJECT Co)//Check simple collision
{
	float tmpl, tmpt, tmpr, tmpb;
	RECT Obj1, Obj2, dest;
	GetBoundingBox(tmpl, tmpt, tmpr, tmpb);
	Obj1.left = tmpl;
	Obj1.top = tmpt;
	Obj1.right = tmpr;
	Obj1.bottom = tmpb;
	Co->GetBoundingBox(tmpl, tmpt, tmpr, tmpb);
	Obj2.left = tmpl;
	Obj2.top = tmpt;
	Obj2.right = tmpr;
	Obj2.bottom = tmpb;
	return IntersectRect(&dest, &Obj2, &Obj1);
}
