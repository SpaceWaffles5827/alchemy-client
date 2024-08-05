#include <alchemy/player.h>

Player::Player(int clientId, const glm::vec3& color, float x, float y)
    : clientId(clientId), color(color), position(x, y) {}

Player::~Player() {}

void Player::render(GLuint shaderProgram, GLuint VAO) const {
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);

    // Set the color uniform
    GLint colorLoc = glGetUniformLocation(shaderProgram, "playerColor");
    glUniform3fv(colorLoc, 1, glm::value_ptr(color));

    // Set the transformation matrix
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(position, 0.0f));
    GLint transformLoc = glGetUniformLocation(shaderProgram, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

    // Draw the player
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindVertexArray(0);
}

void Player::updatePosition(float x, float y) {
    position = glm::vec2(x, y);
}

glm::vec2 Player::getPosition() const {
    return position;
}

int Player::getClientId() const {
    return clientId;
}