/**
 * @brief Bindable object abstract class
 * @date 2020-04-30
 */

#pragma once

/**
 * @brief Bindable object abstract class
 */
class ABindable
{
public:
    virtual ~ABindable() = default;

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

protected:
    unsigned int _id;
};