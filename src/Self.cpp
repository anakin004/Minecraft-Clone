#include "Self.h"
#include "World.h"
#include "shaderClass.h"

Self::Self(glm::vec3 pos) : m_Camera(WIDTH, HEIGHT, pos, 55.0f, 1.0f, 100.0f)
{
	
	glm::mat4 identity( 1.0f );
	m_Camera.SetMVP( identity, false );

}

void Self::Render(Shader* shader) {
	m_PlayerModel.Render(shader);
}

void Self::updatePerspective( Shader* base, Shader* light, Shader* model)
{
	glm::mat4 identityMatrix(1.0f);

	m_Camera.Inputs( window );	
	m_Camera.SetMVP(identityMatrix, false);

	// useing for diffuse and specular lighting, not needed
	//base->SetUniformVec3f("u_camPos", glm::normalize(m_Camera.GetPos()));
	base->Bind();
	m_Camera.PushMVP(base, "u_camMatrix");


	light->Bind();
	m_Camera.PushMVP(light, "u_camMatrix");

	m_Camera.SetMVP(identityMatrix, true);
	model->Bind();
	m_Camera.PushMVP(model, "u_camMatrix");


}
