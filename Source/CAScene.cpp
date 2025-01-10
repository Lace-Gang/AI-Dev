#include "CAScene.h"
#include "ExampleScene.h"
#include "Random.h"

const color_t white = { 255, 255, 255, 255 };
const color_t black = { 0, 0, 0, 255 };

bool CAScene::Initialize()
{
	m_renderer.Initialize();
	m_renderer.CreateWindow("CA", 800, 600);

	m_input.Initialize();
	m_input.Update();

	m_framebuffer = std::make_unique<Framebuffer>(m_renderer, m_renderer.m_width / 2, m_renderer.m_height / 2);
	m_cells = std::make_unique<Cells<uint8_t>>(m_renderer.m_width / 2, m_renderer.m_height / 2);


	return true;
}

void CAScene::Update()
{
	Scene::Update();

	m_framebuffer->Clear(color_t{ 0, 0, 0, 255 }); //had to move the clearing of the framebuffer to before the writing of the cells

	m_cells->Write(m_cells->m_width / 2, 0, 1 );

	//DIFFERENT RULES GIVE YOU DIFFERENT PATTERNS!!!
	int rule = 18; //rule of 30
	//try 30, 18, 22, 57

	//write cells to the frame buffer
	for (int y = 0; y < m_cells->m_height - 1; y++)
	{
		for (int x = 1; x < m_cells->m_width - 1; x++) //starting at zero will have it reading -1 (which is obviously bad)
		{
			int i = 0; // 0 to 7 (eight different values)

			// |= is or equals (I think), so these are all either one OR zero
			//ALSO using bit shifting (<< 1)
			i |= m_cells->Read(x, y) << 1; //0-1
			i |= m_cells->Read(x - 1, y) << 2; //0-1 
			i |= m_cells->Read(x + 1, y); //0-1

			//unsigned int (uint8_t)
			uint8_t state = (rule & 1 << i);
			m_cells->Write(x, y + 1, state);
		}
	}

	// Write cells to the frame buffer
	for (int i = 0; i < m_cells->m_data.size(); i++)
	{

		m_framebuffer->m_buffer[i] = (m_cells->m_data[i]) ? white : black;
	}
}

void CAScene::Draw()
{
	//m_framebuffer->Clear(color_t{ 0, 0, 0, 255 });

	// update framebuffer
	m_framebuffer->Update();

	// show screen
	m_renderer = *m_framebuffer;
	SDL_RenderPresent(m_renderer.m_renderer);
}
