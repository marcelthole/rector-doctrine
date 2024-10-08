<?php

namespace Rector\Doctrine\Tests\CodeQuality\Rector\Property\ImproveDoctrineCollectionDocTypeInEntityRector\Fixture\ManyToMany;

use DateTimeImmutable;
use Doctrine\Common\Collections\ArrayCollection;
use Doctrine\Common\Collections\Collection;
use Doctrine\DBAL\Types\Types;
use Doctrine\ORM\Mapping as ORM;

#[ORM\Entity]
class SkipCollectionGenericObject
{
    /**
     * @var Collection<int, object>
     */
    #[ORM\ManyToMany(mappedBy: 'port', targetEntity: object::class)]
    private Collection $oi;

    public function __construct()
    {
        $this->oi = new ArrayCollection();
    }
}
