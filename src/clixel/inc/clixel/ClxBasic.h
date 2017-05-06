class ClxBasic
{
public:
    ClxBasic();
    virtual ~ClxBasic();

    // Controls whether 'update' and 'draw' are automatically called by FlxState/FlxGroup
    bool IsExist() const;
    void SetExist(bool val);

    // Controls whether 'update' is automatically called by FlxState/FlxGroup
    bool IsActive() const;
    void SetActive(bool val);

    // Controls whether 'draw' is automatically called by FlxState/FlxGroup
    bool IsVisible() const;
    void SetVisible(bool val);

    bool IsAlive() const;
    void SetAlive(bool val);

    // Called before update on each object in the game loop
    virtual void PreUpdate();

    // Override this function update your object's position and appearance. This is where
    // most of your game rules and behavior will go.
    virtual void Update();

    // Called after update on each object in the game loop
    virtual void PostUpdate();

    // Override this function to control how the object is drawn. Rarely necessary.
    virtual void Draw();

    // Handy function for "killing" game objects.
    // Default behavior is to flag them as nonexistent AND dead.
    // However, if you want the "corpse" to remain in the game,
    // like to animate an effect or whatever, you should override this,
    // setting only alive to false, and leaving exists true.
    virtual void Kill();

    // Sets the object back to being alive and existing
    void Revive();

private:
    bool _exists;
    bool _active;
    bool _visible;
    bool _alive;
    // TODO: std::vector<Camera> _cameras;
};

typedef std::shared_ptr<ClxBasic> spClxBasic;