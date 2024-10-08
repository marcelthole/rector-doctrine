<?php

namespace Rector\Doctrine\Tests\CodeQuality\Rector\Property\ImproveDoctrineCollectionDocTypeInEntityRector\Fixture\ManyToMany;

use Doctrine\Common\Collections\Collection;
use Doctrine\ORM\Mapping as ORM;
use Rector\Doctrine\Tests\CodeQuality\Rector\Property\ImproveDoctrineCollectionDocTypeInEntityRector\Source\Training;

/**
 * @ORM\Entity
 */
class VarStatic
{
    /**
     * @ORM\ManyToMany(targetEntity=Training::class, mappedBy="trainer")
     * @var Collection|Training[]
     */
    private $trainings = [];

    /**
     * @var string
     */
    private static $value = '';

    public static function getValue()
    {
        return self::$value;
    }

    public static function setValue(string $value)
    {
        self::$value = $value;
    }
}

?>
-----
<?php

namespace Rector\Doctrine\Tests\CodeQuality\Rector\Property\ImproveDoctrineCollectionDocTypeInEntityRector\Fixture\ManyToMany;

use Doctrine\Common\Collections\Collection;
use Doctrine\ORM\Mapping as ORM;
use Rector\Doctrine\Tests\CodeQuality\Rector\Property\ImproveDoctrineCollectionDocTypeInEntityRector\Source\Training;

/**
 * @ORM\Entity
 */
class VarStatic
{
    /**
     * @ORM\ManyToMany(targetEntity=Training::class, mappedBy="trainer")
     * @var \Doctrine\Common\Collections\Collection<int, \Rector\Doctrine\Tests\CodeQuality\Rector\Property\ImproveDoctrineCollectionDocTypeInEntityRector\Source\Training>
     */
    private $trainings = [];

    /**
     * @var string
     */
    private static $value = '';

    public static function getValue()
    {
        return self::$value;
    }

    public static function setValue(string $value)
    {
        self::$value = $value;
    }
}

?>
